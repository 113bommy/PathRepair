
convert = {
    '0':[],
    '1':[],
    '2':[2],
    '3':[3],
    '4':[3,2,2],
    '5':[5],
    '6':[5,3],
    '7':[7],
    '8':[7,2,2,2],
    '9':[9]
}

input()
n = input()
ans = []
for c in n:
    ans += convert[c]

for i in sorted(ans,reverse=True):
    print(i,end='')
print()
