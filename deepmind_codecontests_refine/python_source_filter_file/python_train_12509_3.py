n = int(input())
l = list(map(int, input().split()))
s = [0,0,0,0,0,0]
d = 0
for i in range(n):
    if(l[i]==4):
        s[0]+=1
    if(l[i]==8 and s[0]>=s[1]):
        s[1]+=1
    elif(l[i]==8):
        d+=1
    if(l[i]==15 and s[0]>s[2] and s[1]>s[2]):
        s[2]+=1
    elif(l[i]==15):
        d+=1
    if(l[i]==16 and s[0]>s[3] and s[1]>s[3] and s[2]>s[3]):
        s[3]+=1
    elif(l[i]==16):
        d+=1
    if(l[i]==23 and s[0]>s[4] and s[1]>s[4] and s[2]>s[4] and s[3]>s[4]):
        s[4]+=1
    elif(l[i]==23):
        d+=1
    if(l[i]==42 and s[0]>s[5] and s[1]>s[5] and s[2]>s[5] and s[3]>s[5] and s[4]>s[5]):
        s[5]+=1
    elif(l[i]==42):
        d+=1
    if(s[0]>0 and s[1]>0 and s[2]>0 and s[3]>0 and s[4]>0 and s[5]>0):
        s[0]-=1
        s[1]-=1
        s[2]-=1
        s[3]-=1
        s[4]-=1
        s[5]-=1
print(d+s[0]+s[1]+s[2]+s[3]+s[4]+s[5])
