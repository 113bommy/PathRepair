#   Codeforces
#   #344A   -   Magnets
#   http://codeforces.com/problemset/problem/344/A
#   12/01/2019
#   Nilton G. M. Junior


if __name__ == '__main__':
    num_magnets = int(input())
    magnet_seq = ''
    for _ in range(num_magnets):
        magnet_seq += input()
    print(magnet_seq.count("00") + magnet_seq.count("11"))
