transition_table = {
    '0': {'0': '1', '1': '2'},
    '1': {'0': '0', '1': '3'},
    '2': {'0': '4', '1': '5'},
    '3': {'0': '4', '1': '5'},
    '4': {'0': '4', '1': '5'},
    '5': {'0': '5', '1': '5'}
}
n = len(transition_table)
print(transition_table, n)
states = set(transition_table.keys())
final_states = {'2', '3', '4'}
non_final = states.difference(final_states)
print(final_states, non_final)
temp = [0] * n
mat = []
for i in range(n):
    mat.append(temp.copy())
for i in range(n):
    for j in range(i):
        state1 = str(i)
        state2 = str(j)
        dict1 = transition_table[state1]
        dict2 = transition_table[state2]
        for key in dict1:
            out1 = dict1[key]
            out2 = dict2[key]
            if ((out1 in final_states) and (out2 not in final_states)) or ((out2 in final_states) and (out1 not in final_states)):
                mat[i][j] = 1
                mat[j][i] = 1
print('states which can be combined are')
for i in range(1, n):
    for j in range(i):
        if mat[i][j] == 0:
            print(i, j)
for ls in mat:
    print(ls)