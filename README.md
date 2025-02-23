# samsung_risc_v
**Samsung RISC-V Internship** – A hands-on exploration of **RISC-V architecture, toolchains, embedded systems, and industry applications**, featuring projects, research, and optimizations for real-world use cases. 
<details>
  <summary>TASK1:Development of C Based LAB</summary>
  <img src="task1/cprogram.png"/>
  <img src="task1/cprogram_output.png"/>
  <img src="task1/riscv_deassembliied text.png"/>
   <img src="task1/riscv_instructions.png"/>
   <img src="task1/riscv_main section.png"/>
   <img src="task1/riscv_open.png"/>
</details>
<details>
  <summary>TASK2:Simulation with Spike</summary>
  <img src="task2/c to riscv.png"/>
   <img src="task2/change of values.png"/>
   <img src="task2/cprogram primeornot.png"/>
   <img src="debug.png"/>
<img src="task2/instruction before 100b0.png"/>
<img src="task2/new command.png"/>
<img src="task2/object dump of 1to5.png"/>
<img src="task2/object dump of primeornot.png"/>
<img src="task2/spike.png"/>
</details>
<details>
  <summary>TASK3:Identification of RISCV instructions</summary>
  <img src="object dump of primeornot.png"/>
# RISC-V Instruction Set Documentation

## 1. auipc a5, 0xfffff
- **Instruction Type:** U-type
- **Opcode:** 0010111 (AUIPC)
- **rd:** a5 (x15) = 01111
- **imm[31:12]:** 0xfffff = 11111111111111111111
- **Binary Encoding:** 11111111111111111111 01111 0010111
- **Hex Representation:** `0xfff00797`

---

## 2. addi a5, a5, -216
- **Instruction Type:** I-type
- **Opcode:** 0010011 (ADDI)
- **funct3:** 000
- **rs1:** a5 (x15) = 01111
- **rd:** a5 (x15) = 01111
- **imm[11:0]:** -216 = 0xFF28 = 1111111100101000
- **Binary Encoding:** 111111110010 01111 000 01111 0010011
- **Hex Representation:** `0x25878793`

---

## 3. beqz a5, 100c8
- **Instruction Type:** B-type
- **Opcode:** 1100011 (BEQ)
- **funct3:** 000
- **rs1:** a5 (x15) = 01111
- **rs2:** x0 = 00000
- **imm[12|10:5|4:1|11]:** 000000000100
- **Binary Encoding:** 0000000 01111 00000 000 0010 1100011
- **Hex Representation:** `0x00078063`

---

## 4. ret (Equivalent to jalr x0, ra, 0)
- **Instruction Type:** I-type
- **Opcode:** 1100111 (JALR)
- **funct3:** 000
- **rs1:** ra (x1) = 00001
- **rd:** x0 = 00000
- **imm[11:0]:** 000000000000
- **Binary Encoding:** 000000000000 00001 000 00000 1100111
- **Hex Representation:** `0x00008067`

---

## 5. auipc gp, 0x1
- **Instruction Type:** U-type
- **Binary Encoding:** 00000000000000000001 00110 0010111
- **Hex Representation:** `0x00010197`

---

## 6. addi gp, gp, -1208
- **Instruction Type:** I-type
- **Binary Encoding:** 111011001000 00110 000 00110 0010011
- **Hex Representation:** `0xb4181913`

---

## 7. addi a0, gp, 1898
- **Instruction Type:** I-type
- **Binary Encoding:** 011101011010 00110 000 01000 0010011
- **Hex Representation:** `0x76418513`

---

## 8. auipc a2, 0x1
- **Instruction Type:** U-type
- **Binary Encoding:** 00000000000000000001 00110 0010111
- **Hex Representation:** `0x00001617`

---

## 9. addi a2, a2, 968
- **Instruction Type:** I-type
- **Binary Encoding:** 000011110000 00110 000 00110 0010011
- **Hex Representation:** `0x24d60613`

---

## 10. sub a2, a2, a0
- **Instruction Type:** R-type
- **Opcode:** 0110011 (SUB)
- **funct7:** 0100000
- **rs1:** a2 (x12) = 01100
- **rs2:** a0 (x10) = 01000
- **rd:** a2 (x12) = 01100
- **Binary Encoding:** 0100000 01000 01100 000 01100 0110011
- **Hex Representation:** `0x40a60633`

---

## 11. auipc ra, 0x0
- **Instruction Type:** U-type
- **Binary Encoding:** 00000000000000000000 00001 0010111
- **Hex Representation:** `0x00000097`

---

## 12. jalr ra, 104(ra)
- **Instruction Type:** I-type
- **Binary Encoding:** 000001101000 00001 000 00001 1100111
- **Hex Representation:** `0x104080e7`

---

## 13. jal ra, 10348 <atexit>
- **Instruction Type:** J-type
- **Opcode:** 1101111 (JAL)
- **rd:** ra (x1) = 00001
- **imm[20|10:1|11|19:12]:** 00100000000000000010
- **Binary Encoding:** 00100000000000000010 00001 1101111
- **Hex Representation:** `0x254000ef`

---

## 14. jal ra, 10330 <__libc_init_array>
- **Instruction Type:** J-type
- **Binary Encoding:** 00100000000000000000 00001 1101111
- **Hex Representation:** `0x240000ef`

---

## 15. lw t0, 0(sp)
- **Instruction Type:** I-type
- **Opcode:** 0000011 (LW)
- **funct3:** 010
- **rs1:** sp (x2) = 00010
- **rd:** t0 (x5) = 00101
- **imm[11:0]:** 000000000000
- **Binary Encoding:** 000000000000 00010 010 00101 0000011
- **Hex Representation:** `0x00012283`

---

## Final Output Summary:
| Instruction | Instruction Type | Hex Representation |
|-------------|----------------|--------------------|
| auipc a5, 0xfffff | U-type | `0xfff00797` |
| addi a5, a5, -216 | I-type | `0x25878793` |
| beqz a5, 100c8 | B-type | `0x00078063` |
| ret | I-type | `0x00008067` |
| auipc gp, 0x1 | U-type | `0x00010197` |
| addi gp, gp, -1208 | I-type | `0xb4181913` |
| addi a0, gp, 1898 | I-type | `0x76418513` |
| auipc a2, 0x1 | U-type | `0x00001617` |
| addi a2, a2, 968 | I-type | `0x24d60613` |
| sub a2, a2, a0 | R-type | `0x40a60633` |
| auipc ra, 0x0 | U-type | `0x00000097` |
| jalr ra, 104(ra) | I-type | `0x104080e7` |
| jal ra, 10348 | J-type | `0x254000ef` |
| jal ra, 10330 | J-type | `0x240000ef` |
| lw t0, 0(sp) | I-type | `0x00012283` |

