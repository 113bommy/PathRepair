def similar_digits(num1,num2):
    result = 0
    for i in range(6):
        if num1[i] == num2[i]:
            result+=1
    return result


def main():
    number_of_codes = eval(input())
    codes = []
    for i in range(number_of_codes):
        codes.append(input())
    #k=3 - завжди будуть путати (4,5,6 так само)
    #k=2? якщо зоча б 2 числа мають 2 однакові цифри то хана не більше ніж 1 однакова цифра
    #k=1? якщо хоча б 2 числа мають 4 однакові цифри то хана не більше ніж 3 однакові цифри
    #k=0? не більше ніж 5 однакових цифр
    max_number_of_similar_digits = 0
    answer = int
    for i in range(number_of_codes-1):
        for j in range(i+1,number_of_codes):
            result = similar_digits(codes[i],codes[j])
            #print('2 numbers: '+str(i+1)+' and '+str(j+1)+" --> "+str(result))
            if result>max_number_of_similar_digits:
                max_number_of_similar_digits = result
            if result>=4:
                answer = 0
                break
        if result>=4:
            answer = 0
            break
    #print(max_number_of_similar_digits)
    if max_number_of_similar_digits == 0 or max_number_of_similar_digits == 1:
        answer = 2
    if max_number_of_similar_digits == 2 or max_number_of_similar_digits == 3:
        answer = 1
    if number_of_codes == 1:
        answer = 6
    print(answer)
main()
