def iq(array):
    for i in range(len(array)):
        diff_array=list()
        c=0
        for j in range(len(array)):
            if j!=i:
                check=even_odd(array[i]-array[j]) 
                diff_array.append(check)
                if even_odd(array[i]-array[j])==diff_array[0]:
                    c+=1                     
                else:
                    break
        if c==len(array)-1:
            break
    print(c-1)
def even_odd(a):
    if a%2==0:
        return True
    else:
        return False
    
n=input()
array=[int(x) for x in input().split()]
iq(array)
        
