cccapstone
==========

c++ bindings for capstone disasembly framework (http://www.capstone-engine.org/ - https://github.com/aquynh/capstone)


**1. clone all (bindings & capstone as well)**

    git clone --recursive https://github.com/zer0mem/cccapstone.git

**2. basic settings**

    add to Additional include directories capstone include : $(SolutionDir)/cccapstone/capstone/include
    

**----------------------------------------------------------------------------------------**

**3. examples**
    
    https://github.com/zer0mem/KernelProject/blob/capstone/KernelProject/src/CapstoneCppBindingsTest.hpp
    
**4. examples by hand (intel x86 - x64)**

    CX86Disasm64 dis; // define disasembler by current needs. 
                      // cccapstone/cppbindings/<ARCHITECTURE>Disasm.hpp for more available bindings
                      
    /*
      f.e. for arm (vice versa with other architectures) can be 
           capstone disasembler created in some ways : 
           
      CArmDisasm64 dis;
      auto dis = CArm64Arch(cs_mode::CS_MODE_ARM + cs_mode::CS_MODE_BUG_ENDIAN, "arm in big endian")
      auto dis = CDisasmbler(cs_mode::CS_MODE_ARM + cs_mode::CS_MODE_BUG_ENDIAN, "arm in big endian", cs_arch::CS_ARCH_ARM64)
    */
    //check if no error occured
    if (dis.GetError())
    	return;
    	
    //set how deep should capstone reverse instruction
    dis.SetDetail(cs_opt_value::CS_OPT_ON);

    //set syntax for output disasembly string
    dis.SetSyntax(cs_opt_value::CS_OPT_SYNTAX_INTEL);
    
    //*OPTIONAL* :) - set callback, when is encountered data - not resolved code -
    dis.SetSkipDataCallback(cs_opt_skipdata{ 
                                ".UNKOWNBYTES : ", 
                                SkipDataCallback, 
                                nullptr 
                                });
    
    //for more settings see cccapstone/cppbindings/CsAdvOptionsWrap.hpp
    
    //process disasembling
    auto insn = dis.Disasm(code, size);
    //check if disassembling succesfull
    if (!insn.get())
    	return;
    
    //print basic info
    for (size_t i = 0; i < insn->Count; i++)
      printf("-> 0x%p:\t%s\t%s\n", 
                insn->Instructions[i].address, 
                insn->Instructions[i].mnemonic, 
                insn->Instructions[i].op_str);
    
    //how to gather advanced info is by example in debug-print function 
    dis.PrintInstDetail(insn->Instructions[i]);
    --> instructioninfox86::print_insn_detail (cccapstone/cppbindings/InsInfo.hpp)
    
    //in future in capstone will be possible also filtering group of instructions (adn far more .. :)
    if (dis.IsInInsGroup(insn->Instructions[i], x86_insn_group::X86_GRP_JUMP))
        printf("\nControl Flow change at : %p", insn->Instructions[i].address);
    
    
    
