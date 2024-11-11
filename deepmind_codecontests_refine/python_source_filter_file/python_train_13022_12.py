number_of_segment_and_upper=input().split()
number_of_segment=int(number_of_segment_and_upper[0])
upper=int(number_of_segment_and_upper[1])
segments=list()
i=0
while i<number_of_segment:
    l_and_r=input().split()
    l=int(l_and_r[0])
    r=int(l_and_r[1])
    segments.append(l)
    segments.append(r)
    i+=1
d=list()
j=1
while j<=upper:
    t=0
    while t <= len(segments)-1:
        if j  in range(segments[t],segments[t+1]+1) and j not in d:
            d.append(j)
            break
        t+=2
    j+=1
if len(d)==0:
    print(0)
else:
    diff = list()
    for j in range(1, upper):
        if j not in d:
            diff.append(j)
    print(len(diff))
    print(*diff)