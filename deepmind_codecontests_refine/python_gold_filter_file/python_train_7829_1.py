s1 = input()
s2 = input()
s3 = input()

first = s1[0] + s2[1] + s3[2]
second = s1[2] + s2[1] + s3[0]
third = s1[1] + s2[1] + s3[1]


if first == first[::-1] and second == second[::-1] and third == third[::-1] and s2 == s2[::-1]:
    print("YES")
else:
    print("NO")