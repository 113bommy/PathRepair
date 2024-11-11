import sys
# input_file = open("in.txt")

input_file = sys.stdin
input_file.readline()

vals = list(map(int,input_file.readline().rstrip().split()))
change = ['0']
for i in range(len(vals)-1):
  if vals[i]<vals[i+1]:
    change+="+"
  elif vals[i]>vals[i+1]:
    change+="-"
  else:
    change+="0"

dp=[(1,0)]

lastPlus = None
lastMinus = None
for i in range(1,len(change)):
  length, symb = dp[i-1]
  if change[i] == '0':
    dp.append((length+1,symb))
  elif change[i] == '+':

    if symb == "+":
      dp.append((i-lastPlus+1,'+'))
    else:
      dp.append((length+1,'+'))
    lastPlus = i

  elif change[i] == '-':
    if symb == '-':
      dp.append((i-lastMinus+1,'-'))
    else:
      dp.append((length+1,'-'))
    lastMinus = i



lengths = [x[0] for x in dp]
print(max(lengths))


# print(vals)
# print(change)
# print(dp)
