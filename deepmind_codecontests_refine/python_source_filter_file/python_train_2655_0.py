'''
n: number of computers
a1 ... an: how many pieces needed to "crack" the computer
each cracked computer gives one piece of information

initially: at first computer
question: how many turns needed to crack all computers

'''

#~ import io
#~ import sys

#~ test = '''3
#~ 0 2 0'''

#~ test = '''5
#~ 4 2 3 0 1'''

#~ test  = '''7
#~ 0 3 1 0 5 2 6
#~ '''

#~ sys.stdin = io.StringIO(test)

direction = 0 # could be +1, or -1

n = int(input())
a = list(map(int, input().split() ))
dirs = (range(n),range(n-1,-1,-1))
pieces = 0
notcracked = n
turns = 0
while notcracked>0: 
   for i in dirs[direction]:
      #~ print(i,n)
      if a[i]!=None and pieces>=a[i]:
         notcracked -= 1
         a[i] = None
         pieces += 1
         print("Cracked",i)
   direction = 1-direction
   turns += 1

print(turns-1)
