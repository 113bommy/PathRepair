num = int(input())
k = list(map(int, input() .split()))
chest = 0
bicep = 0
back = 0
for x in range(0,num):
    if x%3==0:
        chest = chest+k[x]
    if x%3==1:
        bicep = bicep+k[x]
    if x%3==2:
        back = back+k[x]
if chest>bicep and chest>back:
    print('chest')
elif bicep>chest and bicep>back:
    print('bicep')
elif back>chest and back>bicep:
    print('back')