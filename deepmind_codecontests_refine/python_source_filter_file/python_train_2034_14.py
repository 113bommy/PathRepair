i = int(input())
if((i>=-127)and(i<=128)):
   print("byte")
elif((i>=-32768)and(i<=32767)):
   print("short")
elif((i>=-2147483648)and(i<=2147483647)):
   print("int")
elif((i>=-9223372036854775808)and(i<=-9223372036854775807)):
   print("long")
else:
   print("BigInteger")
