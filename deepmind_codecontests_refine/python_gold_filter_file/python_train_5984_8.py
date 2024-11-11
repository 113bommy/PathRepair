S=input()
cnt=0
ls=[]
for each in set(S):
    ls.append(S.count(each))
for i in ls:
    cnt+=pow(i,2)
print(cnt)