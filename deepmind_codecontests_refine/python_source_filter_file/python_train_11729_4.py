n = int(input())

kuroo = input()
shiro = input()
katie = input()




kuroo_dict = {}
shiro_dict = {}
katie_dict = {}

# for i in range(len(kuroo)) :

#     if kuroo[i] in kuroo_dict :
#         kuroo_dict[kuroo[i]] += 1
#     else :
#         kuroo_dict[kuroo[i]] = 1


# for i in range(len(shiro)) :

#     if shiro[i] in shiro_dict :
#         shiro_dict[shiro[i]] += 1
#     else :
#         shiro_dict[shiro[i]] = 1

# for i in range(len(katie)) :

#     if katie[i] in katie_dict :
#         katie_dict[katie[i]] += 1
#     else :
#         katie_dict[katie[i]] = 1


ans_kuroo , ans_shiro , ans_katie = 0 , 0 , 0

def calc(d , string , n) :

    for i in range(len(d)) :

        if string[i] in d :
            d[string[i]] += 1
        else :
            d[string[i]] = 1

    m = 0

    for key in d:
        m = max(m , d[key])

    #print(m , d)

    if m == len(string) and n == 1 :

        m = len(string) - 1
    else :
        m = min(m + n , len(string))

    



    return m 


ans_kuroo = (calc(kuroo_dict , kuroo , n))
ans_shiro = (calc(shiro_dict , shiro , n))
ans_katie = (calc(katie_dict , katie , n))
ans = max(ans_kuroo , ans_shiro , ans_katie)


#print(ans_kuroo , ans_shiro , ans_katie , len(katie))

if (ans_kuroo == ans_katie and ans_kuroo == ans) or (ans_katie == ans_shiro and ans_shiro == ans) or (ans_shiro == ans_kuroo and ans_kuroo == ans) :
    print("Draw")
else :
    if ans == ans_kuroo :
        print("Kuro")
    elif ans == ans_shiro :
        print("Shiro")
    else :
        print("Katie")














