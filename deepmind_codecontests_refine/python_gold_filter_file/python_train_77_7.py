d={'AC':0,'WA':0,'TLE':0,'RE':0}
n=int(input())
for i in range(0,n):
    d[input()]+=1
for j in d:
    print(j,"x",d[j])