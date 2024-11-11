flags=input()
first=input()
second=input()



try:
    startToFinish1=flags.index(first)
except:
    startToFinish1 = len(flags) + 1
try:
    startToFinish2=flags.rindex(second)
except :
    startToFinish2 = -1

flags=flags[len(flags)::-1]


try:
    finishToStart1=flags.index(first)
except:
    finishToStart1=len(flags)+1
try:
    finishToStart2=flags.rindex(second)
except:
    finishToStart2 = -1

if(startToFinish1+len(first)-1<startToFinish2 and finishToStart1+len(first)-1<finishToStart2):
    print('both')
elif (startToFinish1+len(first)-1<startToFinish2):
    print('forward')
elif (finishToStart1+len(first)-1<finishToStart2):
    print('backward')
else :
    print('fantasy')






