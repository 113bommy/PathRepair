from sys import stdin, stdout

def main():
    number_of_elements_in_A_B = stdin.readline().rstrip()
    k_m = [int(i) for i in stdin.readline().rstrip().split()]
    k = k_m[0]
    m = k_m[1]
    listA = [int(i) for i in stdin.readline().rstrip().split()]
    listB = [int(i) for i in stdin.readline().rstrip().split()]

    k_members_of_A = listA[:k]
    m_members_of_B = listB[-m:]

    if max(k_members_of_A) <= min(m_members_of_B):
        return 'YES'
    else:
        return 'NO'

print(main())
