input()
s = input()
m = {'0':[],'1':[],'2':[2],'3':[3],'4':[2,2,3],'5':[5],
    '6':[3,5],'7':[7],'8':[2,2,2,7],'9':[2,3,3,7]}
r = []
for c in s:
    r += m[c]
r = sorted(r,reverse=True)
print (''.join(str(x) for x in r))