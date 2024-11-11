input()
p=[0]*100001
for i in list(map(int,input().split())):
    p[i]+=1
for x in p:
    if x%2:
        print('Conan')
        break
else:
    print('Agasa')