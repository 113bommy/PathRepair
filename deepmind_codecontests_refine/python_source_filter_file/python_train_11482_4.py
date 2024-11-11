import math
from collections import Counter
t = int(input())
for i in range(t):
    n = int(input())
    l = list(map(int,input().split()))
    counter = Counter(l)
    least = counter.most_common()[-1]
    least_freq = least[1]
    least_num = least[0]
    index_of_freq_element = [ j for j in range(n) if(l[j]==least_num)]
    index_of_other_element = [ j for j in range(n) if(l[j]!=least_num)]
    print(index_of_freq_element)
    print(index_of_other_element)
    if(least_freq<=n-1):
        print("YES")
        for j in index_of_other_element:
            print(index_of_freq_element[0]+1, j+1)
        pos = 0
        for j in index_of_freq_element[1:]:
            print(index_of_other_element[pos]+1, j+1)
            pos+=1
    else:
        print("NO")
    
    
    

    
