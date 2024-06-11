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

Joseph:
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
  addi $sp, $sp, -640
  lw $t0, -440($fp)
  li $t0,0
  sw $t0, -440($fp)
  lw $t1, -440($fp)
  lw $t2, -444($fp)
  move $t2,$t1
  sw $t2, -444($fp)
  sw $t1, -440($fp)
  lw $t3, -448($fp)
  move $t3,$a0
  sw $t3, -448($fp)
  lw $t4, -448($fp)
  lw $t5, -452($fp)
  move $t5,$t4
  sw $t5, -452($fp)
  sw $t4, -448($fp)
  lw $t6, -456($fp)
  li $t6,0
  sw $t6, -456($fp)
  lw $t7, -456($fp)
  lw $t0, -460($fp)
  move $t0,$t7
  sw $t0, -460($fp)
  sw $t7, -456($fp)
  lw $t1, -464($fp)
  li $t1,0
  sw $t1, -464($fp)
  lw $t2, -464($fp)
  lw $t3, -468($fp)
  move $t3,$t2
  sw $t3, -468($fp)
  sw $t2, -464($fp)
label0:
  lw $t4, -444($fp)
  lw $t5, -472($fp)
  move $t5,$t4
  sw $t5, -472($fp)
  sw $t4, -444($fp)
  lw $t6, -476($fp)
  move $t6,$a0
  sw $t6, -476($fp)
  lw $t7, -476($fp)
  lw $t0, -472($fp)
  blt $t0, $t7, label1
  sw $t0, -472($fp)
  sw $t7, -476($fp)
  j label2
label1:
  lw $t1, -480($fp)
  addi $t1,$fp,-436
  sw $t1, -480($fp)
  lw $t2, -444($fp)
  lw $t3, -484($fp)
  move $t3,$t2
  sw $t3, -484($fp)
  sw $t2, -444($fp)
  li $t4,4
  lw $t5, -484($fp)
  lw $t6, -488($fp)
  mul $t6,$t5,$t4
  sw $t6, -488($fp)
  sw $t5, -484($fp)
  lw $t7, -488($fp)
  lw $t0, -480($fp)
   add $t0,$t0,$t7
  sw $t0, -480($fp)
  sw $t7, -488($fp)
  lw $t1, -480($fp)
  lw $t2, -492($fp)
  move $t2,$t1
  sw $t2, -492($fp)
  sw $t1, -480($fp)
  lw $t3, -496($fp)
  li $t3,1
  sw $t3, -496($fp)
  lw $t5, -496($fp)
  move $t4,$t5
  lw $t6, -492($fp)
  sw $t4,0($t6)
  sw $t5, -496($fp)
  sw $t6, -492($fp)
  lw $t7, -444($fp)
  lw $t0, -500($fp)
  move $t0,$t7
  sw $t0, -500($fp)
  sw $t7, -444($fp)
  lw $t1, -504($fp)
  li $t1,1
  sw $t1, -504($fp)
  lw $t2, -504($fp)
  lw $t3, -500($fp)
  lw $t4, -508($fp)
   add $t4,$t3,$t2
  sw $t4, -508($fp)
  sw $t2, -504($fp)
  sw $t3, -500($fp)
  lw $t5, -508($fp)
  lw $t6, -444($fp)
  move $t6,$t5
  sw $t6, -444($fp)
  sw $t5, -508($fp)
  j label0
label2:
label3:
  lw $t7, -452($fp)
  lw $t0, -512($fp)
  move $t0,$t7
  sw $t0, -512($fp)
  sw $t7, -452($fp)
  lw $t1, -516($fp)
  li $t1,2
  sw $t1, -516($fp)
  lw $t2, -516($fp)
  lw $t3, -512($fp)
  bgt $t3, $t2, label4
  sw $t2, -516($fp)
  sw $t3, -512($fp)
  j label5
label4:
  lw $t4, -520($fp)
  addi $t4,$fp,-436
  sw $t4, -520($fp)
  lw $t5, -460($fp)
  lw $t6, -524($fp)
  move $t6,$t5
  sw $t6, -524($fp)
  sw $t5, -460($fp)
  li $t7,4
  lw $t0, -524($fp)
  lw $t1, -528($fp)
  mul $t1,$t0,$t7
  sw $t1, -528($fp)
  sw $t0, -524($fp)
  lw $t2, -528($fp)
  lw $t3, -520($fp)
   add $t3,$t3,$t2
  sw $t3, -520($fp)
  sw $t2, -528($fp)
  lw $t4, -520($fp)
  lw $t5, -532($fp)
  move $t5,$t4
  sw $t5, -532($fp)
  sw $t4, -520($fp)
  lw $t6, -536($fp)
  li $t6,1
  sw $t6, -536($fp)
  lw $t7, -536($fp)
  lw $t0, -532($fp)
  lw $t0,0($t0)
  beq $t0, $t7, label6
  sw $t0, -532($fp)
  sw $t7, -536($fp)
  j label7
label6:
  lw $t1, -468($fp)
  lw $t2, -540($fp)
  move $t2,$t1
  sw $t2, -540($fp)
  sw $t1, -468($fp)
  lw $t3, -544($fp)
  li $t3,1
  sw $t3, -544($fp)
  lw $t4, -544($fp)
  lw $t5, -540($fp)
  lw $t6, -548($fp)
   add $t6,$t5,$t4
  sw $t6, -548($fp)
  sw $t4, -544($fp)
  sw $t5, -540($fp)
  lw $t7, -548($fp)
  lw $t0, -468($fp)
  move $t0,$t7
  sw $t0, -468($fp)
  sw $t7, -548($fp)
  lw $t1, -552($fp)
  li $t1,3
  sw $t1, -552($fp)
  lw $t2, -468($fp)
  lw $t3, -556($fp)
  move $t3,$t2
  sw $t3, -556($fp)
  sw $t2, -468($fp)
  lw $t4, -556($fp)
  lw $t5, -552($fp)
  beq $t5, $t4, label8
  sw $t4, -556($fp)
  sw $t5, -552($fp)
  j label9
label8:
  lw $t6, -560($fp)
  addi $t6,$fp,-436
  sw $t6, -560($fp)
  lw $t7, -460($fp)
  lw $t0, -564($fp)
  move $t0,$t7
  sw $t0, -564($fp)
  sw $t7, -460($fp)
  li $t1,4
  lw $t2, -564($fp)
  lw $t3, -568($fp)
  mul $t3,$t2,$t1
  sw $t3, -568($fp)
  sw $t2, -564($fp)
  lw $t4, -568($fp)
  lw $t5, -560($fp)
   add $t5,$t5,$t4
  sw $t5, -560($fp)
  sw $t4, -568($fp)
  lw $t6, -560($fp)
  lw $t7, -572($fp)
  move $t7,$t6
  sw $t7, -572($fp)
  sw $t6, -560($fp)
  lw $t0, -576($fp)
  li $t0,0
  sw $t0, -576($fp)
  lw $t2, -576($fp)
  move $t1,$t2
  lw $t3, -572($fp)
  sw $t1,0($t3)
  sw $t2, -576($fp)
  sw $t3, -572($fp)
  lw $t4, -580($fp)
  li $t4,0
  sw $t4, -580($fp)
  lw $t5, -580($fp)
  lw $t6, -468($fp)
  move $t6,$t5
  sw $t6, -468($fp)
  sw $t5, -580($fp)
  lw $t7, -452($fp)
  lw $t0, -584($fp)
  move $t0,$t7
  sw $t0, -584($fp)
  sw $t7, -452($fp)
  lw $t1, -588($fp)
  li $t1,1
  sw $t1, -588($fp)
  lw $t2, -588($fp)
  lw $t3, -584($fp)
  lw $t4, -592($fp)
   sub $t4,$t3,$t2
  sw $t4, -592($fp)
  sw $t2, -588($fp)
  sw $t3, -584($fp)
  lw $t5, -592($fp)
  lw $t6, -452($fp)
  move $t6,$t5
  sw $t6, -452($fp)
  sw $t5, -592($fp)
label9:
label7:
  lw $t7, -460($fp)
  lw $t0, -596($fp)
  move $t0,$t7
  sw $t0, -596($fp)
  sw $t7, -460($fp)
  lw $t1, -600($fp)
  li $t1,1
  sw $t1, -600($fp)
  lw $t2, -600($fp)
  lw $t3, -596($fp)
  lw $t4, -604($fp)
   add $t4,$t3,$t2
  sw $t4, -604($fp)
  sw $t2, -600($fp)
  sw $t3, -596($fp)
  lw $t5, -604($fp)
  lw $t6, -460($fp)
  move $t6,$t5
  sw $t6, -460($fp)
  sw $t5, -604($fp)
  lw $t7, -460($fp)
  lw $t0, -608($fp)
  move $t0,$t7
  sw $t0, -608($fp)
  sw $t7, -460($fp)
  lw $t1, -612($fp)
  move $t1,$a0
  sw $t1, -612($fp)
  lw $t2, -612($fp)
  lw $t3, -608($fp)
  beq $t3, $t2, label10
  sw $t2, -612($fp)
  sw $t3, -608($fp)
  j label11
label10:
  lw $t4, -616($fp)
  li $t4,0
  sw $t4, -616($fp)
  lw $t5, -616($fp)
  lw $t6, -460($fp)
  move $t6,$t5
  sw $t6, -460($fp)
  sw $t5, -616($fp)
label11:
  j label3
label5:
  lw $t7, -620($fp)
  li $t7,0
  sw $t7, -620($fp)
  lw $t0, -620($fp)
  lw $t1, -444($fp)
  move $t1,$t0
  sw $t1, -444($fp)
  sw $t0, -620($fp)
label12:
  lw $t2, -444($fp)
  lw $t3, -624($fp)
  move $t3,$t2
  sw $t3, -624($fp)
  sw $t2, -444($fp)
  lw $t4, -628($fp)
  move $t4,$a0
  sw $t4, -628($fp)
  lw $t5, -628($fp)
  lw $t6, -624($fp)
  blt $t6, $t5, label13
  sw $t5, -628($fp)
  sw $t6, -624($fp)
  j label14
label13:
  lw $t7, -632($fp)
  li $t7,1
  sw $t7, -632($fp)
  lw $t0, -636($fp)
  addi $t0,$fp,-436
  sw $t0, -636($fp)
  lw $t1, -444($fp)
  lw $t2, -640($fp)
  move $t2,$t1
  sw $t2, -640($fp)
  sw $t1, -444($fp)
  li $t3,4
  lw $t4, -640($fp)
  lw $t5, -644($fp)
  mul $t5,$t4,$t3
  sw $t5, -644($fp)
  sw $t4, -640($fp)
  lw $t6, -644($fp)
  lw $t7, -636($fp)
   add $t7,$t7,$t6
  sw $t7, -636($fp)
  sw $t6, -644($fp)
  lw $t0, -636($fp)
  lw $t1, -648($fp)
  move $t1,$t0
  sw $t1, -648($fp)
  sw $t0, -636($fp)
  lw $t2, -648($fp)
  lw $t2,0($t2)
  lw $t3, -632($fp)
  beq $t3, $t2, label15
  sw $t2, -648($fp)
  sw $t3, -632($fp)
  j label16
label15:
  lw $t4, -444($fp)
  lw $t5, -652($fp)
  move $t5,$t4
  sw $t5, -652($fp)
  sw $t4, -444($fp)
  lw $t6, -656($fp)
  li $t6,1
  sw $t6, -656($fp)
  lw $t7, -656($fp)
  lw $t0, -652($fp)
  lw $t1, -660($fp)
   add $t1,$t0,$t7
  sw $t1, -660($fp)
  sw $t0, -652($fp)
  sw $t7, -656($fp)
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
  lw $a0, -660($fp)
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
label16:
  lw $t2, -444($fp)
  lw $t3, -664($fp)
  move $t3,$t2
  sw $t3, -664($fp)
  sw $t2, -444($fp)
  lw $t4, -668($fp)
  li $t4,1
  sw $t4, -668($fp)
  lw $t5, -668($fp)
  lw $t6, -664($fp)
  lw $t7, -672($fp)
   add $t7,$t6,$t5
  sw $t7, -672($fp)
  sw $t5, -668($fp)
  sw $t6, -664($fp)
  lw $t0, -672($fp)
  lw $t1, -444($fp)
  move $t1,$t0
  sw $t1, -444($fp)
  sw $t0, -672($fp)
  j label12
label14:
  lw $t2, -676($fp)
  li $t2,0
  sw $t2, -676($fp)
  lw $t3, -676($fp)
  move $v0, $t3
  sw $t3, -676($fp)
  addi $sp, $sp, 244
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
  addi $sp, $sp, -48
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
  lw $t4, -40($fp)
  move $t4,$v0
  sw $t4, -40($fp)
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
  lw $t5, -40($fp)
  lw $t6, -44($fp)
  move $t6,$t5
  sw $t6, -44($fp)
  sw $t5, -40($fp)
  lw $t7, -48($fp)
  li $t7,0
  sw $t7, -48($fp)
  lw $t0, -44($fp)
  lw $t1, -52($fp)
  move $t1,$t0
  sw $t1, -52($fp)
  sw $t0, -44($fp)
  lw $t2, -56($fp)
  li $t2,3
  sw $t2, -56($fp)
  lw $t3, -56($fp)
  lw $t4, -52($fp)
  bgt $t4, $t3, label22
  sw $t3, -56($fp)
  sw $t4, -52($fp)
  j label21
label22:
  lw $t5, -44($fp)
  lw $t6, -60($fp)
  move $t6,$t5
  sw $t6, -60($fp)
  sw $t5, -44($fp)
  lw $t7, -64($fp)
  li $t7,100
  sw $t7, -64($fp)
  lw $t0, -64($fp)
  lw $t1, -60($fp)
  ble $t1, $t0, label20
  sw $t0, -64($fp)
  sw $t1, -60($fp)
  j label21
label20:
  lw $t2, -48($fp)
  li $t2,1
  sw $t2, -48($fp)
label21:
  li $t3,0
  lw $t4, -48($fp)
  bne $t4, $t3, label18
  sw $t4, -48($fp)
  j label17
label17:
  lw $t5, -68($fp)
  li $t5,1
  sw $t5, -68($fp)
  lw $t6, -68($fp)
  li $t7,0
  lw $t0, -72($fp)
   sub $t0,$t7,$t6
  sw $t0, -72($fp)
  sw $t6, -68($fp)
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
  j label19
label18:
  lw $t1, -44($fp)
  lw $t2, -76($fp)
  move $t2,$t1
  sw $t2, -76($fp)
  sw $t1, -44($fp)
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
  lw $a0, -76($fp)
  jal Joseph
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
  lw $t3, -80($fp)
  move $t3,$v0
  sw $t3, -80($fp)
label19:
  lw $t4, -84($fp)
  li $t4,0
  sw $t4, -84($fp)
  lw $t5, -84($fp)
  move $v0, $t5
  sw $t5, -84($fp)
  addi $sp, $sp, 48
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
