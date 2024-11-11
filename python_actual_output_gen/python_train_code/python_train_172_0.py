def score(value,time,wrongAnswer):
    return max(.3*value,(1-time/250.0)*value-(50 * wrongAnswer))

def actualScore():
    times=input().split()
    times=list(map(int,times))
    wrongAnswer=input().split()
    wrongAnswer=list(map(int,wrongAnswer))
    temp=input().split()
    temp=list(map(int,temp))
    total=0
    for problem in range(len(times)):
        total+=score(500*(problem+1),times[problem],wrongAnswer[problem])
    total+=100*int(temp[0])
    total+=50*int(temp[1])
    return int(total)

print(actualScore())
