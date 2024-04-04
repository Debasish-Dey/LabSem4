# states = int(input('Enter no of states : '))
# alpha = int(input('Enter the no of alphabets : '))
# temp = [''] * (alpha + 2)
# mat = []
# for i in range(states):
#     mat.append(temp.copy())
# print('Enter the values in following format\n')
# print('State Alpha1 Alpha2 Output')
# print(len(mat), len(mat[0]))
# for i in range(len(mat)):
#     for j in range(len(mat[0])):
#         mat[i][j] = input()
#
# print(mat)

states = 3
alpha = 2
mat = [['A', 'A', 'B', '0'], ['B', 'B', 'C', '1'], ['C', 'B', 'C', '0']]
t_table = {}
d = {}
alphabets = []
for ls in mat:
    d[ls[0]] = ls[alpha + 1]
    if ls[alpha + 1] not in alphabets:
        alphabets.append(ls[alpha + 1])
for ls in mat:
    t_table[ls[0]] = {}
    cur_alpha = '0'
    for i in range(alpha):
        t_table[ls[0]][cur_alpha] = (d[ls[i + 1]], ls[i + 1])
        cur_alpha = chr(ord(cur_alpha) + 1)
print(t_table)