/* 
若给定的序列X = {x1,x2,…,xm},则另一序列Z = {z1,z2,…,zk}，
是X的子序列是指存在一个严格下表序列{i1,i2,…,ik}使得对于所有的j = 1,2,…k有zj = xij。
例如，序列Z = {B,C,D,B}是序列X = {A,B,C,B,D,A,B}的子序列，相应的递增下标序列为{2,3,5,7}。
给定2个序列X和Y，当另一序列Z既是X的子序列又是Y的子序列时，称Z是序列X和Y的公共子序列。
问题表述：给定2个序列X={x1,x2,…,xm}和Y = {y1,y2,…,yn}，找出X和Y的最长公共子序列。

主题：最长公共子序列
* 作者：chinazhangjie
* 邮箱：chinajiezhang@gmail.com
* 开发语言：C++
* 开发环境：Microsoft Visual Studio 2008
* 时间: 2010.11.14
*/
#include <iostream>
#include <vector>
using namespace std ;

// longest common sequence
class LonComSequence
{
public:
    typedef vector<vector<int> >    LCS_Type ;
    typedef vector<vector<int> >    MarkType ;

public:
    LonComSequence (const vector<char>& vSeq1,
                    const vector<char>& vSeq2) 
        : mc_nEqual (1), mc_nSq1move(2), mc_nSq2move(3)
    {
        m_vSeq1 = vSeq1 ;
        m_vSeq2 = vSeq2 ;
        m_nLen1 = vSeq1.size() ;
        m_nLen2 = vSeq2.size() ;

        // 初始化最长公共子序列的长度
        m_lcsLen.resize (m_nLen1 + 1) ;
        m_mtMark.resize (m_nLen1 + 1) ;
        for (int i = 0; i < m_nLen1 + 1; ++ i) {
            m_lcsLen[i].resize (m_nLen2 + 1) ;
            m_mtMark[i].resize (m_nLen2 + 1) ;
        }
    }

    // 计算最长公共子序列的长度
    int calLcsLength ()    
    {
        for (int i = 1; i <= m_nLen1; ++ i) {
            m_lcsLen[i][0] = 0 ; // 序列二的长度为0，公共子序列的长度为0
        } 
        for (int i = 1; i <= m_nLen2; ++ i) {
            m_lcsLen[0][i] = 0 ; // 序列一的长度为0，公共子序列的长度为0
        }
    
        for (int i = 0; i < m_nLen1; ++ i) {
            for (int j = 0; j < m_nLen2; ++ j) {
                if (m_vSeq1[i] == m_vSeq2[j]) {
                    m_lcsLen[i+1][j+1] = m_lcsLen[i][j] + 1 ;
                    m_mtMark[i+1][j+1] = mc_nEqual ;
                }
                else if (m_lcsLen[i][j+1] >= m_lcsLen[i+1][j]) {
                    m_lcsLen[i+1][j+1] = m_lcsLen[i][j+1] ;
                    m_mtMark[i+1][j+1] = mc_nSq1move ;
                }
                else {
                    m_lcsLen[i+1][j+1] = m_lcsLen[i+1][j] ;
                    m_mtMark[i+1][j+1] = mc_nSq2move ;
                }
            }
        }
        return m_lcsLen[m_nLen1][m_nLen2] ;
    }
    // 构造最长公共子序列
    void LCS() {
        cout << "LCS is : " ;
        __LCS(m_nLen1, m_nLen2);
        cout << endl ;
    }

private:
    void __LCS (int i, int j) 
    {
        if (i == 0 || j == 0) {
            return ;
        }

        if (m_mtMark[i][j] == mc_nEqual) {
            __LCS (i - 1, j - 1) ;
            cout << m_vSeq1[i - 1] << " " ;
        }
        else if (m_mtMark[i][j] == mc_nSq1move) {
            __LCS (i - 1, j) ;
        }
        else {
            __LCS (i, j - 1) ;
        }
    }

private:
    vector<char>    m_vSeq1 ;    // 序列一
    vector<char>    m_vSeq2 ;    // 序列二
    int                m_nLen1 ;    // 序列一的长度
    int                m_nLen2 ;    // 序列二的长度
    LCS_Type        m_lcsLen ;    // 最长公共子序列的长度
    MarkType        m_mtMark ;    // 记录m_lcsLen
    const int mc_nEqual ;        // 相等的标志
    const int mc_nSq1move ;        // 序列一左移的标志
    const int mc_nSq2move ;        // 序列二左移的标志
} ;


int main()
{
    vector<char> s1 ; 
    s1.push_back ('A') ;
    s1.push_back ('B') ;
    s1.push_back ('C') ;
    s1.push_back ('D') ;
    s1.push_back ('E') ;
    s1.push_back ('F') ;

    vector<char> s2 ;
    s2.push_back ('B') ;
    s2.push_back ('D') ;
    s2.push_back ('F') ;
    s2.push_back ('G') ;
    s2.push_back ('H') ;

    LonComSequence lcs(s1, s2) ;
    cout << lcs.calLcsLength () << endl ;
    lcs.LCS();

    return 0 ;
}