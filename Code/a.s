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
  addi $sp, $sp, -276
  lw $t0, -60($fp)
  li $t0,0
  sw $t0, -60($fp)
  lw $t1, -60($fp)
  lw $t2, -64($fp)
  move $t2,$t1
  sw $t2, -64($fp)
  sw $t1, -60($fp)
  lw $t3, -68($fp)
  li $t3,5
  sw $t3, -68($fp)
  lw $t4, -68($fp)
  lw $t5, -72($fp)
  move $t5,$t4
  sw $t5, -72($fp)
  sw $t4, -68($fp)
  lw $t6, -76($fp)
  li $t6,0
  sw $t6, -76($fp)
  lw $t7, -76($fp)
  lw $t0, -80($fp)
  move $t0,$t7
  sw $t0, -80($fp)
  sw $t7, -76($fp)
label0:
  lw $t1, -64($fp)
  lw $t2, -84($fp)
  move $t2,$t1
  sw $t2, -84($fp)
  sw $t1, -64($fp)
  lw $t3, -88($fp)
  li $t3,5
  sw $t3, -88($fp)
  lw $t4, -88($fp)
  lw $t5, -84($fp)
  blt $t5, $t4, label1
  sw $t4, -88($fp)
  sw $t5, -84($fp)
  j label2
label1:
  lw $t6, -92($fp)
  addi $t6,$fp,-56
  sw $t6, -92($fp)
  lw $t7, -64($fp)
  lw $t0, -96($fp)
  move $t0,$t7
  sw $t0, -96($fp)
  sw $t7, -64($fp)
  li $t1,4
  lw $t2, -96($fp)
  lw $t3, -100($fp)
   mul $t3,$t2,$t1
  sw $t3, -100($fp)
  sw $t2, -96($fp)
  lw $t4, -100($fp)
  lw $t5, -92($fp)
   add $t5,$t5,$t4
  sw $t5, -92($fp)
  sw $t4, -100($fp)
  lw $t6, -92($fp)
  lw $t7, -104($fp)
  move $t7,$t6
  sw $t7, -104($fp)
  sw $t6, -92($fp)
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
  jal read
  lw $t0, -108($fp)
  move $t0,$v0
  sw $t0, -108($fp)
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
  lw $t2, -108($fp)
  move $t1,$t2
  lw $t3, -104($fp)
  sw $t1,0($t3)
  sw $t2, -108($fp)
  sw $t3, -104($fp)
  lw $t4, -64($fp)
  lw $t5, -112($fp)
  move $t5,$t4
  sw $t5, -112($fp)
  sw $t4, -64($fp)
  lw $t6, -116($fp)
  li $t6,1
  sw $t6, -116($fp)
  lw $t7, -116($fp)
  lw $t0, -112($fp)
  lw $t1, -120($fp)
   add $t1,$t0,$t7
  sw $t1, -120($fp)
  sw $t0, -112($fp)
  sw $t7, -116($fp)
  lw $t2, -120($fp)
  lw $t3, -64($fp)
  move $t3,$t2
  sw $t3, -64($fp)
  sw $t2, -120($fp)
  j label0
label2:
  lw $t4, -72($fp)
  lw $t5, -124($fp)
  move $t5,$t4
  sw $t5, -124($fp)
  sw $t4, -72($fp)
  lw $t6, -124($fp)
  lw $t7, -64($fp)
  move $t7,$t6
  sw $t7, -64($fp)
  sw $t6, -124($fp)
label3:
  lw $t0, -64($fp)
  lw $t1, -128($fp)
  move $t1,$t0
  sw $t1, -128($fp)
  sw $t0, -64($fp)
  lw $t2, -132($fp)
  li $t2,0
  sw $t2, -132($fp)
  lw $t3, -132($fp)
  lw $t4, -128($fp)
  bgt $t4, $t3, label4
  sw $t3, -132($fp)
  sw $t4, -128($fp)
  j label5
label4:
label6:
  lw $t5, -80($fp)
  lw $t6, -136($fp)
  move $t6,$t5
  sw $t6, -136($fp)
  sw $t5, -80($fp)
  lw $t7, -64($fp)
  lw $t0, -140($fp)
  move $t0,$t7
  sw $t0, -140($fp)
  sw $t7, -64($fp)
  lw $t1, -144($fp)
  li $t1,1
  sw $t1, -144($fp)
  lw $t2, -144($fp)
  lw $t3, -140($fp)
  lw $t4, -148($fp)
   sub $t4,$t3,$t2
  sw $t4, -148($fp)
  sw $t2, -144($fp)
  sw $t3, -140($fp)
  lw $t5, -148($fp)
  lw $t6, -136($fp)
  blt $t6, $t5, label7
  sw $t5, -148($fp)
  sw $t6, -136($fp)
  j label8
label7:
  lw $t7, -152($fp)
  addi $t7,$fp,-56
  sw $t7, -152($fp)
  lw $t0, -80($fp)
  lw $t1, -156($fp)
  move $t1,$t0
  sw $t1, -156($fp)
  sw $t0, -80($fp)
  li $t2,4
  lw $t3, -156($fp)
  lw $t4, -160($fp)
   mul $t4,$t3,$t2
  sw $t4, -160($fp)
  sw $t3, -156($fp)
  lw $t5, -160($fp)
  lw $t6, -152($fp)
   add $t6,$t6,$t5
  sw $t6, -152($fp)
  sw $t5, -160($fp)
  lw $t7, -152($fp)
  lw $t0, -164($fp)
  move $t0,$t7
  sw $t0, -164($fp)
  sw $t7, -152($fp)
  lw $t1, -168($fp)
  li $t1,3
  sw $t1, -168($fp)
  lw $t2, -168($fp)
  lw $t3, -164($fp)
  lw $t3,0($t3)
  bgt $t3, $t2, label9
  sw $t2, -168($fp)
  sw $t3, -164($fp)
  j label10
label9:
  lw $t4, -172($fp)
  addi $t4,$fp,-56
  sw $t4, -172($fp)
  lw $t5, -80($fp)
  lw $t6, -176($fp)
  move $t6,$t5
  sw $t6, -176($fp)
  sw $t5, -80($fp)
  li $t7,4
  lw $t0, -176($fp)
  lw $t1, -180($fp)
   mul $t1,$t0,$t7
  sw $t1, -180($fp)
  sw $t0, -176($fp)
  lw $t2, -180($fp)
  lw $t3, -172($fp)
   add $t3,$t3,$t2
  sw $t3, -172($fp)
  sw $t2, -180($fp)
  lw $t4, -172($fp)
  lw $t5, -184($fp)
  move $t5,$t4
  sw $t5, -184($fp)
  sw $t4, -172($fp)
  lw $t6, -184($fp)
  lw $t6,0($t6)
  lw $t7, -188($fp)
  move $t7,$t6
  sw $t7, -188($fp)
  sw $t6, -184($fp)
  lw $t0, -192($fp)
  addi $t0,$fp,-56
  sw $t0, -192($fp)
  lw $t1, -80($fp)
  lw $t2, -196($fp)
  move $t2,$t1
  sw $t2, -196($fp)
  sw $t1, -80($fp)
  li $t3,4
  lw $t4, -196($fp)
  lw $t5, -200($fp)
   mul $t5,$t4,$t3
  sw $t5, -200($fp)
  sw $t4, -196($fp)
  lw $t6, -200($fp)
  lw $t7, -192($fp)
   add $t7,$t7,$t6
  sw $t7, -192($fp)
  sw $t6, -200($fp)
  lw $t0, -192($fp)
  lw $t1, -204($fp)
  move $t1,$t0
  sw $t1, -204($fp)
  sw $t0, -192($fp)
  lw $t2, -208($fp)
  addi $t2,$fp,-56
  sw $t2, -208($fp)
  lw $t3, -80($fp)
  lw $t4, -212($fp)
  move $t4,$t3
  sw $t4, -212($fp)
  sw $t3, -80($fp)
  lw $t5, -216($fp)
  li $t5,1
  sw $t5, -216($fp)
  lw $t6, -216($fp)
  lw $t7, -212($fp)
  lw $t0, -220($fp)
   add $t0,$t7,$t6
  sw $t0, -220($fp)
  sw $t6, -216($fp)
  sw $t7, -212($fp)
  li $t1,4
  lw $t2, -220($fp)
  lw $t3, -224($fp)
   mul $t3,$t2,$t1
  sw $t3, -224($fp)
  sw $t2, -220($fp)
  lw $t4, -224($fp)
  lw $t5, -208($fp)
   add $t5,$t5,$t4
  sw $t5, -208($fp)
  sw $t4, -224($fp)
  lw $t6, -208($fp)
  lw $t7, -228($fp)
  move $t7,$t6
  sw $t7, -228($fp)
  sw $t6, -208($fp)
  lw $t1, -228($fp)
  lw $t1,0($t1)
  move $t0,$t1
  lw $t2, -204($fp)
  sw $t0,0($t2)
  sw $t1, -228($fp)
  sw $t2, -204($fp)
  lw $t3, -232($fp)
  addi $t3,$fp,-56
  sw $t3, -232($fp)
  lw $t4, -80($fp)
  lw $t5, -236($fp)
  move $t5,$t4
  sw $t5, -236($fp)
  sw $t4, -80($fp)
  lw $t6, -240($fp)
  li $t6,1
  sw $t6, -240($fp)
  lw $t7, -240($fp)
  lw $t0, -236($fp)
  lw $t1, -244($fp)
   add $t1,$t0,$t7
  sw $t1, -244($fp)
  sw $t0, -236($fp)
  sw $t7, -240($fp)
  li $t2,4
  lw $t3, -244($fp)
  lw $t4, -248($fp)
   mul $t4,$t3,$t2
  sw $t4, -248($fp)
  sw $t3, -244($fp)
  lw $t5, -248($fp)
  lw $t6, -232($fp)
   add $t6,$t6,$t5
  sw $t6, -232($fp)
  sw $t5, -248($fp)
  lw $t7, -232($fp)
  lw $t0, -252($fp)
  move $t0,$t7
  sw $t0, -252($fp)
  sw $t7, -232($fp)
  lw $t1, -188($fp)
  lw $t2, -256($fp)
  move $t2,$t1
  sw $t2, -256($fp)
  sw $t1, -188($fp)
  lw $t4, -256($fp)
  move $t3,$t4
  lw $t5, -252($fp)
  sw $t3,0($t5)
  sw $t4, -256($fp)
  sw $t5, -252($fp)
label10:
  lw $t6, -80($fp)
  lw $t7, -260($fp)
  move $t7,$t6
  sw $t7, -260($fp)
  sw $t6, -80($fp)
  lw $t0, -264($fp)
  li $t0,1
  sw $t0, -264($fp)
  lw $t1, -264($fp)
  lw $t2, -260($fp)
  lw $t3, -268($fp)
   add $t3,$t2,$t1
  sw $t3, -268($fp)
  sw $t1, -264($fp)
  sw $t2, -260($fp)
  lw $t4, -268($fp)
  lw $t5, -80($fp)
  move $t5,$t4
  sw $t5, -80($fp)
  sw $t4, -268($fp)
  j label6
label8:
  lw $t6, -272($fp)
  li $t6,0
  sw $t6, -272($fp)
  lw $t7, -272($fp)
  lw $t0, -80($fp)
  move $t0,$t7
  sw $t0, -80($fp)
  sw $t7, -272($fp)
  lw $t1, -64($fp)
  lw $t2, -276($fp)
  move $t2,$t1
  sw $t2, -276($fp)
  sw $t1, -64($fp)
  lw $t3, -280($fp)
  li $t3,1
  sw $t3, -280($fp)
  lw $t4, -280($fp)
  lw $t5, -276($fp)
  lw $t6, -284($fp)
   sub $t6,$t5,$t4
  sw $t6, -284($fp)
  sw $t4, -280($fp)
  sw $t5, -276($fp)
  lw $t7, -284($fp)
  lw $t0, -64($fp)
  move $t0,$t7
  sw $t0, -64($fp)
  sw $t7, -284($fp)
  j label3
label5:
  lw $t1, -288($fp)
  li $t1,0
  sw $t1, -288($fp)
  lw $t2, -288($fp)
  lw $t3, -64($fp)
  move $t3,$t2
  sw $t3, -64($fp)
  sw $t2, -288($fp)
label11:
  lw $t4, -64($fp)
  lw $t5, -292($fp)
  move $t5,$t4
  sw $t5, -292($fp)
  sw $t4, -64($fp)
  lw $t6, -296($fp)
  li $t6,5
  sw $t6, -296($fp)
  lw $t7, -296($fp)
  lw $t0, -292($fp)
  blt $t0, $t7, label12
  sw $t0, -292($fp)
  sw $t7, -296($fp)
  j label13
label12:
  lw $t1, -300($fp)
  addi $t1,$fp,-56
  sw $t1, -300($fp)
  lw $t2, -64($fp)
  lw $t3, -304($fp)
  move $t3,$t2
  sw $t3, -304($fp)
  sw $t2, -64($fp)
  li $t4,4
  lw $t5, -304($fp)
  lw $t6, -308($fp)
   mul $t6,$t5,$t4
  sw $t6, -308($fp)
  sw $t5, -304($fp)
  lw $t7, -308($fp)
  lw $t0, -300($fp)
   add $t0,$t0,$t7
  sw $t0, -300($fp)
  sw $t7, -308($fp)
  lw $t1, -300($fp)
  lw $t2, -312($fp)
  move $t2,$t1
  sw $t2, -312($fp)
  sw $t1, -300($fp)
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
  lw $a0, -312($fp)
  lw $a0,0($a0)
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
  lw $t3, -64($fp)
  lw $t4, -316($fp)
  move $t4,$t3
  sw $t4, -316($fp)
  sw $t3, -64($fp)
  lw $t5, -320($fp)
  li $t5,1
  sw $t5, -320($fp)
  lw $t6, -320($fp)
  lw $t7, -316($fp)
  lw $t0, -324($fp)
   add $t0,$t7,$t6
  sw $t0, -324($fp)
  sw $t6, -320($fp)
  sw $t7, -316($fp)
  lw $t1, -324($fp)
  lw $t2, -64($fp)
  move $t2,$t1
  sw $t2, -64($fp)
  sw $t1, -324($fp)
  j label11
label13:
  lw $t3, -328($fp)
  li $t3,0
  sw $t3, -328($fp)
  lw $t4, -328($fp)
  move $v0, $t4
  sw $t4, -328($fp)
  addi $sp, $sp, 276
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
