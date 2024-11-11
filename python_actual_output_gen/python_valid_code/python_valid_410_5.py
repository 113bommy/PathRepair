n=int(input())
ch1=''
for i in range (1,n+1):
    if (i % 2)==0:
        ch1=ch1+'I hate that '
    else:
        ch1=ch1+'I love that '
ch1=ch1[:12*n-5]+'it'
print(ch1)
