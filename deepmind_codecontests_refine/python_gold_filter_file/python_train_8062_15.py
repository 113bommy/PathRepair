n=int(input())
line=input().split()
data=[int(i) for i in line]
data.sort(reverse=True)
score = 0

if n>=4:
    for i in range(2,len(data)):
        score=score+(int(data[i])*(int(n-i+1)))
    score=score+int(int(n)*int(data[1]))
    score=score+int(int(n)*int(data[0]))
elif n==3:
    score = score+(int(data[2])*2)
    score = score+int(3*int(data[1]))
    score = score+int(3*int(data[0]))
elif n==2:
    score = score+int(2*int(data[1]))+int(2*int(data[0]))
elif n==1:
    score = int(data[0])
print(score)
