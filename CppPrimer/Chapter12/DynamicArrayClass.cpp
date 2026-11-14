class V_arry{
private:
    const int m_len;
    int *m_arr;
public:
    V_arry(int len);

};
V_arry::V_arry(int len):m_len(len){
    m_arr = new int[len];
}
