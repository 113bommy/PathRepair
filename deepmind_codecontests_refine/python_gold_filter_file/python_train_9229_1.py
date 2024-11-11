col,k = map(int,input().split(' '))
print('YES')
print('.'*col)
if k%2==0:
    print('.'+'#'*(k//2)+'.'*(col-1-(k//2)))
    print('.'+'#'*(k//2)+'.'*(col-1-(k//2)))
else:
    if(col-2>=k):
        print('.'*((col-k)//2)+'#'*(k)+'.'*((col-k)//2))
        print('.'*(col))
    else:
        print('.'+'#'*(col-2)+'.')
        print('.'*((col-k+col-2)//2)+'#'*(k-col+2-1)+'.'+'#'+'.'*((col-k+col-2)//2))
print('.'*(col))
