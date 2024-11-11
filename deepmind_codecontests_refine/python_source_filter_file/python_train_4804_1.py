k,m=int(input()),1500;a=m-k%m
print(m,*[0]*(m-2)+[-a,(k+a)//m+a])