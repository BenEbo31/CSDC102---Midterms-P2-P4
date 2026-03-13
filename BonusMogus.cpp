//bonus-mogus

// add #include <fstream>


// Log transaction to CSV file
void logTransactionToCSV(const string& cardNum, const string& type,
                    double amount, double fee) {
    ofstream file("transactions.csv", ios::app);

    if (file.is_open()) {

        time_t now = time(0);
        tm * t = localtime(&now);

        file << (t -> tm_mon + 1) << "/" << t -> tm_mday << "/" << (t -> tm_year + 1900) 
             << "," << t -> tm_hour << ":" << t -> tm_min << ",";
            
        file << cardNum << "," << type << "," << amount << "," << fee << endl;

        file.close();
    }
    else {
        cerr << "Error: Could not open transactions.csv\n" << endl;
    }
}
