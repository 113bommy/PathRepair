def function(n):
    if n%2==0:
        return 'NO'
    if int((n-3)/2)>=0:
        return f'{1} {int((n-3)/2)}'
    return 'NO'
if __name__=="__main__":
    n=int(input())
    print(function(n))