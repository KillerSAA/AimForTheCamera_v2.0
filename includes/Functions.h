// << functions >>
:OpenIniFile
    0DD0: pFileName = get_label_addr @func // android
    0DD0: pMode = get_label_addr @mode // android
    0DD0: OpenFile = get_label_addr @_ZN8CFileMgr8OpenFileEPKcS1_ // android
    0DD1: OpenFile = get_func_addr_by_cstr_name OpenFile // CFileMgr::OpenFile

    0DD3: context_set_reg 0 value pFileName // teste.ini
    0DD3: context_set_reg 1 value pMode // "rt"
    0DD2: context_call_func OpenFile
    0DD4: IniFile = context_get_reg 0 // android
    if IniFile <> false // if file open
return

:GetValueFromIni
    ReadLineIni()

    if DATATYPE == _integer
    then
        0DD0: DATATYPE = get_label_addr @int
    end
    if DATATYPE == _float
    then
        0DD0: DATATYPE = get_label_addr @float
    end

    0DD0: ReturnValue = get_label_addr @value  // value = 4 bytes
    0DD0: pStr = get_label_addr @string
    0DD0: pStr_buff = get_label_addr @string_buff
    0DD0: pEqual = get_label_addr @equal
    0DD0: buffer = get_label_addr @buffer

    0@ = 0x18D7B8 //v1.08 = 0x179670
    0DD7: imageb = get_image_base
    005A: 0@ += imageb // (int)


    0DD3: context_set_reg 0 value buffer
    0DD3: context_set_reg 1 value pStr
    0DD3: context_set_reg 2 value pStr_buff
    0DD3: context_set_reg 3 value pEqual
    0DD2: context_call_func 0@ // sscanf

    0DD3: context_set_reg 0 value buffer
    0DD3: context_set_reg 1 value DATATYPE
    0DD3: context_set_reg 2 value ReturnValue
    0DD2: context_call_func 0@ // sscanf

    DATATYPE = 0
    0DD8: ReturnValue = read_mem_addr ReturnValue size 4 add_ib 0
return

:ReadLineIni
    0DD0: buffer = get_label_addr @buffer // android
    0DD0: ReadLine = get_label_addr @_ZN8CFileMgr8ReadLineEjPci
    0DD1: ReadLine = get_func_addr_by_cstr_name ReadLine
    0DD3: context_set_reg 0 value IniFile
    0DD3: context_set_reg 1 value buffer
    0DD3: context_set_reg 2 value 512
    0DD2: context_call_func ReadLine
    0DD8: ReadLine = read_mem_addr buffer size 1 add_ib 0 // android
    if and
    ReadLine <> 0xA // Line Feed
    ReadLine <> 0x5B // [
    ReadLine <> 0x3B // ;
    ReadLine <> 0x23 // #
    jf @ReadLineIni
return

:CloseIni
    0DD0: CloseFile = get_label_addr @_ZN8CFileMgr9CloseFileEj // android
    0DD1: CloseFile = get_func_addr_by_cstr_name CloseFile // android
    0DD3: context_set_reg 0 value IniFile // android
    0DD2: context_call_func CloseFile // android
return

