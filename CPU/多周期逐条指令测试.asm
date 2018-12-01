 .text
#################################################################################
#8条指令逐条指令测试
#################################################################################
 .text
sort_init:
 addi $s0,$0,-1
 addi $s1,$0,0
 sw $s0,128($s1)
 lw $s3,128($s2)     
 add $s2,$s0,$s3
 slt $t0,$s0,$s3
 beq $t0,$zero,next   #branch
 nop                  
 next:
 beq $s0,$zero,next  #no branch

 bne $s0,$zero,next1  #branch
 nop
next1:
  bne $t0,$zero,next1  #branch
   addi   $v0,$zero,10         # system call for exit
 syscall                  # we are out of here.   
