s=input();c=[f=0]*26
for i in s:c[ord(i)-97]+=1
for i in c:f+=i%2
print("YNeos"[(f>0)::2])