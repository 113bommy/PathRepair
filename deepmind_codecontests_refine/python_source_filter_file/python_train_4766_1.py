X,Y= map(int,input().split())
if y%2==0 and 2*X<=Y and Y<=4*X:
    print('yes')
else:
    print('No')