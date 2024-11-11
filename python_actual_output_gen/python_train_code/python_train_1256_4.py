from datetime import date
import sys
for line in sys.stdin.readlines():
   m , d = map(int,line.split())
   if m != 0 and d != 0 :
       val = date(2004,m,d)
       day = val.isoweekday()
       if day == 0:
           print("Sunday")
       elif day == 1:
           print("Monday")
       elif day == 2:
           print("Tuesday")
       elif day == 3:
           print("Wednesday")
       elif day == 4:
           print("Thursday")
       elif day == 5:
           print("Friday")
       else:
           print("Saturday")
   else:
       break