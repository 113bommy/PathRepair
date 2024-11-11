# Читаем ввод
data = input().split(" ")

# Парсим ввод
for i in range(4):
    data[i] = int(data[i])

lenght = data[0]
data.remove(data[0])

data.sort()

max_num = data[2]
mid_num = data[1]
min_num = data[0]

if min_num == 1:
    print(lenght)
    quit()

# Проверяем самый легкий вариант

if lenght % min_num == 0:
     print(int(lenght / min_num))
     quit()

max_summ = 0

# Ну а если не прокатило...

if not(max_num == mid_num or max_num == min_num or mid_num == min_num):    

    max_c = lenght // max_num + 1
    max_bc = (lenght // mid_num + 1) + (lenght // max_num + 1)

    pa = min_num * (lenght // min_num + 2)
    for a in range(lenght // min_num + 1, -1, -1):
        pa -= min_num        
        if max_summ >= a + max_c + (lenght - pa) // mid_num + 2:
            break    
        
        pb = ((lenght - pa) // mid_num + 2 + 1) * mid_num    
        for b in range((lenght - pa) // mid_num + 2, -1, -1):       
                
            pb -= mid_num
            tmp1 = lenght - pa - pb            
            if tmp1 >= max_num:
                c = (tmp1) / max_num
                if not c.is_integer():
                    continue
                
            elif tmp1 == 0:
                c = 0
            else:
                continue       
                    
            if a + b + c > max_summ:
                max_summ = a + b + c
else:
    print("Got rid of 1 number!!!")
    max_2n = max(max_num, mid_num)
    min_2n = min(mid_num, min_num)

    print("New min max", min_2n, max_2n)

    pa = min_2n * (lenght // min_2n + 2)
    for a in range(lenght // min_2n + 1, -1, -1):
        
        pa -= min_2n
        pb = lenght - pa
        b = pb / max_2n
        if not b.is_integer():
            continue
        #print(b)
                   
        if a + b > max_summ:
            print("New max summ", a, b)
            max_summ = a + b


                
print(int(max_summ))