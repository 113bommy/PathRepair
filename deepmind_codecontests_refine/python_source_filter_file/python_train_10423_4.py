n =int(input())
cups = input()

def maxlength(cups):
    length = 0
    for i in cups:
        if i == 'G':
            length =  length + 1
    return length
  
ll = cups.split('S')
themax = maxlength(cups)
maxl = 0
length =0
for i in range(len(ll)):
    if len(ll[i])>0 and length > 0:
        length = len(ll[i]) + length
        if length >maxl :
            maxl = length
        length = len(ll[i])
    if length == 0 or len(ll[i]) ==0:
        length = len(ll[i])
    if length> maxl and length< themax:
        maxl = length
if maxl < themax:
    maxl  = maxl + 1
print(maxl)