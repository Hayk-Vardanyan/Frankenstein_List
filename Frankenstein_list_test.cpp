int main()
{
    FList<int> lst;
    lst.push_back(1000);
    lst.push_back(2);
    lst.push_back(8);
    lst.push_back(4);
    lst.push_back(999);
    lst.insert(2, 99);
    lst.removeAt(4);
    
    lst.print_in_ascending_order();
}

