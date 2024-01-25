#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

using namespace std;

int n, c, w; // ���� n��, �ڸ��� ��� c, ���� ���� w
int trees[51];
int max_val = -987654321;

long long solve(int tree_len) {
    int tree_cnt = 0;
    int tree_cut_cnt = 0;
    long long temp_ans = 0;
    for (int i = 0; i < n; i++) {
        int tmp_tree_cnt = tree_cnt;
        int tmp_tree_cut_cnt = tree_cut_cnt;

        if (trees[i] < tree_len) continue;

        if (trees[i] == tree_len) {
            tree_cnt++;
            // continue;
        }
        else if (trees[i] % tree_len == 0) {
            tree_cnt += trees[i] / tree_len;
            tree_cut_cnt += trees[i] / tree_len - 1;
        }
        else {
            tree_cnt += trees[i] / tree_len;
            tree_cut_cnt += trees[i] / tree_len;
        }

        // ���� ����
        long long temp_cur = (long long)tree_cnt * tree_len * w - c * tree_cut_cnt;

        if (temp_ans > temp_cur) {
            tree_cnt = tmp_tree_cnt;
            tree_cut_cnt = tmp_tree_cut_cnt;
        }
        else
            temp_ans = temp_cur;
        // ���� ��
    }

    // �캯���� int Ÿ�Գ��� �����ؼ� long long���� �����ָ� overflow �߻���
    temp_ans = (long long)tree_cnt * tree_len * w - c * tree_cut_cnt;

    return temp_ans;
}


int main() {
    cin >> n >> c >> w;

    for (int i = 0; i < n; i++) {
        cin >> trees[i];
        if (max_val < trees[i]) max_val = trees[i];
    }

    long long ans = -987654321;
    for (int tree_len = 1; tree_len <= max_val; tree_len++) {
        long long ret = solve(tree_len);
        if (ret > ans) ans = ret;
    }

    printf("%lld\n", ans);
    return 0;
}