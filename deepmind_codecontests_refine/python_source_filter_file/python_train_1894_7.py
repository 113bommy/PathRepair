first_number=int(input())
for i in range (first_number):
    number = int(input())
    number_str=str(input())
    number_list=[int(n) for n in number_str.split()]
    for k in range (1,11):
        num=2**k
        m=0
        for j in range (100):
            if num in number_list:
                number_list.remove(num)
                m=m+1
        m_=m//2
        for x in range (m_):
            number_list.append(num*2)
    if 2048 in number_list:
        print("YES")
    else:print("NO")
        
        