.data
_prompt: .asciiz "Enter an integer:"
_ret: .asciiz "\n"
.globl main
.text
read:
  li $v0, 4
  la $a0, _prompt
  syscall
  li $v0, 5
  syscall
  jr $ra

write:
  li $v0, 1
  syscall
  li $v0, 4
  la $a0, _ret
  syscall
  move $v0, $0
  jr $ra

main:
move $fp, $sp
addi $sp, $sp, -:
li $t8,1
move $t9,$t8
move $t10,$t9
move $t11,$t10
li $t12,3
move $t11,$t12
