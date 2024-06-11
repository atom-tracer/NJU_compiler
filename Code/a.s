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
  addi $sp, $sp, -36
  sw $fp, 32($sp)
  addi $fp, $sp, 36
  sw $s0, 0($sp)
  sw $s1, 4($sp)
  sw $s2, 8($sp)
  sw $s3, 12($sp)
  sw $s4, 16($sp)
  sw $s5, 20($sp)
  sw $s6, 24($sp)
  sw $s7, 28($sp)
  addi $sp, $sp, -68
  lw $t0, -56($fp)
  lw $t1, -52($fp)
  move $t1,$t0
  sw $t1, -52($fp)
  sw $t0, -56($fp)
  lw $t2, -60($fp)
  li $t2,0
  sw $t2, -60($fp)
  lw $t3, -60($fp)
  lw $t4, -64($fp)
  muli $t4,$t3,4
  sw $t3, -60($fp)
  sw $t4, -64($fp)
  lw $t5, -64($fp)
  lw $t6, -52($fp)
  add $t6,$t6,$t5
  sw $t6, -52($fp)
  sw $t5, -64($fp)
  lw $t7, -52($fp)
  sw $t7, -52($fp)
  lw $t0, -52($fp)
  lw $t1, -68($fp)
  move $t1,$t0
  sw $t1, -68($fp)
  sw $t0, -52($fp)
  addi $sp,$sp,-60
  sw $t0,16($sp)
  sw $t1,20($sp)
  sw $t2,24($sp)
  sw $t3,28($sp)
  sw $t4,32($sp)
  sw $t5,36($sp)
  sw $t6,40($sp)
  sw $t7,44($sp)
  sw $t8,48($sp)
  sw $t9,52($sp)
  sw $a0,0($sp)
  sw $a1,4($sp)
  sw $a2,8($sp)
  sw $a3,12($sp)
  sw $ra,56($sp)
  lw $a0, -72($fp)
  jal read
  lw $t0,16($sp)
  lw $t1,20($sp)
  lw $t2,24($sp)
  lw $t3,28($sp)
  lw $t4,32($sp)
  lw $t5,36($sp)
  lw $t6,40($sp)
  lw $t7,44($sp)
  lw $t8,48($sp)
  lw $t9,52($sp)
  lw $a0,0($sp)
  lw $a1,4($sp)
  lw $a2,8($sp)
  lw $a3,12($sp)
  lw $ra,56($sp)
  addi $sp,$sp,60
  lw $t2, -76($fp)
  move $t2,$v0
  sw $t2, -76($fp)
  lw $t3, -56($fp)
  lw $t4, -84($fp)
  move $t4,$t3
  sw $t4, -84($fp)
  sw $t3, -56($fp)
  lw $t5, -88($fp)
  li $t5,0
  sw $t5, -88($fp)
  lw $t6, -88($fp)
  lw $t7, -92($fp)
  muli $t7,$t6,4
  sw $t6, -88($fp)
  sw $t7, -92($fp)
  lw $t0, -92($fp)
  lw $t1, -84($fp)
  add $t1,$t1,$t0
  sw $t1, -84($fp)
  sw $t0, -92($fp)
  lw $t2, -84($fp)
  sw $t2, -84($fp)
  lw $t3, -84($fp)
  lw $t4, -96($fp)
  move $t4,$t3
  sw $t4, -96($fp)
  sw $t3, -84($fp)
  addi $sp,$sp,-60
  sw $t0,16($sp)
  sw $t1,20($sp)
  sw $t2,24($sp)
  sw $t3,28($sp)
  sw $t4,32($sp)
  sw $t5,36($sp)
  sw $t6,40($sp)
  sw $t7,44($sp)
  sw $t8,48($sp)
  sw $t9,52($sp)
  sw $a0,0($sp)
  sw $a1,4($sp)
  sw $a2,8($sp)
  sw $a3,12($sp)
  sw $ra,56($sp)
  lw $a0, -100($fp)
  jal write
  lw $t0,16($sp)
  lw $t1,20($sp)
  lw $t2,24($sp)
  lw $t3,28($sp)
  lw $t4,32($sp)
  lw $t5,36($sp)
  lw $t6,40($sp)
  lw $t7,44($sp)
  lw $t8,48($sp)
  lw $t9,52($sp)
  lw $a0,0($sp)
  lw $a1,4($sp)
  lw $a2,8($sp)
  lw $a3,12($sp)
  lw $ra,56($sp)
  addi $sp,$sp,60
  lw $t5, -104($fp)
  li $t5,0
  sw $t5, -104($fp)
  lw $t6, -104($fp)
  move $v0, $t6
  sw $t6, -104($fp)
  addi $sp, $sp, 68
  lw $s0, 0($sp)
  lw $s1, 4($sp)
  lw $s2, 8($sp)
  lw $s3, 12($sp)
  lw $s4, 16($sp)
  lw $s5, 20($sp)
  lw $s6, 24($sp)
  lw $s7, 28($sp)
  lw $fp, 32($sp)
  addi $sp, $sp, 36
  jr $ra
