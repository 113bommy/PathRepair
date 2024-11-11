# Allahumma SalliI Ala Muhammadiw Wa Ala Aali Muhammadin
# Kamaa Sal’laita Ala Ibrahima Wa Ala Aali Ibrahima Inna’ka Hamidum Majid.
# Allahumma Baarik Ala Muhammadiw Wa Ala Aali Muhammadin
# Kamaa Baarakta Ala Ibrahima Wa Ala Aali Ibrahima Inna’ka Hamidum Majid.

def TwoThePowersum (n):
    pow2 = 1;
    sum=0;
    while (pow2 <= n):
            sum +=pow2;
            pow2 *=2;
    return sum;
#main Function :
test = int(input())
for i in range(test):
    number = int(input())
    sum= (number*(number+1))//2
    ans = TwoThePowersum(number);
    print(sum-2*ans)
    #print(sum_b)