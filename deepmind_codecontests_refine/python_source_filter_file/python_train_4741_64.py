
import sys
data = sys.stdin.readline()
index = int( data )

##try outputting Fibonacci numbers???
##1 --> 1, 2 --> 1, and so on.
#
#n = 2
#fn = 1
#fnMinus1 = 1
#
#while n < index :
#    n = n + 1
#    fnTemporary = fn
#    fn = fn + fnMinus1 #store the new fibonacci number
#    fnMinus1 = fnTemporary #load the old fibonacci number from temp storage
#
#print( fn )

##Take 2: try outputting index * 2/3, rounded UP to nearest integer??
#
#roundedDownVersion = index * 2 // 3
##add one, but only if index * 2/3 is not an integer.
#roundedUpVersion = roundedDownVersion
#if (index * 2) % 3 != 0 :
#    roundedUpVersion += 1
#
#if index == 2 :
#    roundedUpVersion = 1
#
#
#print( roundedUpVersion )

#if index is multiple of 3, then return index * 2/3.
if index % 3 == 0 :
    print( index * 2 / 3 )
else :
    multipleOfThree = index // 3
    print( 2*multipleOfThree + 1 )
