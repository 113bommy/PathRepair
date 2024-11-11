A=input().split()
k=int(A[0])
d=int(A[1])
t=int(A[2])
if k<=d:
    if t%(k+(d-k)/2)<=k:
        dob=t%(k+(d-k)/2)
    else:
        dob=k+ 2*(t%(k+(d-k)/2)-k)
    tay=d*(t//(k+(d-k)/2))+dob
else:
    if t%(k+(d-((k-1)%d+1))/2)<=k:
        dob=t%(k+(d-((k-1)%d+1))/2)
    else:
      dob=k+((t%(k+(d-((k-1)%d+1))/2)-k)*2)
    tay=t//(k+(d-((k-1)%d+1))/2)*d*((k-1)//d+1)+dob
print(tay)