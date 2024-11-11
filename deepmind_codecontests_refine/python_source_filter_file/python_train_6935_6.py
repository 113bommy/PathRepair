h, m, s, t1, t2 = [int(i) for i in input().split(" ")]
if h == 12:
    h = 0
h = h + (m/60) + (s/3600)
m = (m/5 + s/60)
s = s/5

if t1 == 12:
    t1 = 0
if t2 == 12:
    t2 = 0
rule = sorted([h,m,s])
#print(rule)

result = "NO"

if rule[0]<t1<rule[1] and rule[0]<t2<rule[1]:
    result = "YES"
elif rule[1]<t1<rule[2] and rule[1]<t2<rule[2]:
    result = "YES"
elif (t1 < rule[0] or t1 > rule[2]) and (t2 < rule[0] or t2 > rule[2]):
    result = "YES"

#print((h,m,s))
print(result)