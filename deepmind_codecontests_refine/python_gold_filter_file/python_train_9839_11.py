import sys
import math
inputlines=sys.stdin.readlines()
number_of_testcases=int(inputlines[0])
def find_largest_2_power(number):
    largest_power=0
    while(number>1):
        largest_power+=1
        number//=2
    return largest_power
for i in range(number_of_testcases):
    number=int(inputlines[i+1])
    largest_power=find_largest_2_power(number)
    #print(number*(number+1))
    sum_till_n=(number*(number+1))//2
    #print(int(sum_till_n))
    sum_of_powers=(math.pow(2,largest_power+1)-1) #sum of gp 2^0,2^1,2^2........2^n
    #print(int(2*sum_of_powers))
    final_ans=int(sum_till_n)-int(2*sum_of_powers)
    print(final_ans)