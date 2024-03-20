class Cashier 
{
private:
    int m_customer = 0;
    int m_specialCustomer;
    float m_discount;
    map<int, int> m_prices;
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices)
    {
        m_specialCustomer = n;
        m_discount = discount;
        for (int i = 0; i < products.size(); i++)
            m_prices.insert(pair<int, int>(products[i], prices[i]));
    }
    
    double getBill(vector<int> product, vector<int> amount) 
    {
        m_customer++;
        double bill = 0.0;
        for (int j = 0; j < product.size(); j++)
            bill += amount[j] * m_prices[product[j]];
        if (m_customer == m_specialCustomer)
        {
            m_customer = 0;
            bill *= ((100 - m_discount) / 100.0);
        }
        return bill;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
