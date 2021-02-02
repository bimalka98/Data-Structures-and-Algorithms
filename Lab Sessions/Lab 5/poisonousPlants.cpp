int poisonousPlants(vector<int> p) {

    int num_of_plants = p.size(); // Number of plants at the begining.
    int days = 0;

    while(true){

        // Trying to get the remaining plants after a day.
        // There's no plant left to the first plant. Therefore it is preserved anyway.
        vector<int> remaining_plants = {p[0]};

        for(int i =1; i< num_of_plants;i++){
            // If left pesticide is greater than or equal to peticide of the current plant: the plant remains alive.
            if(p[i] <= p[i-1]) remaining_plants.push_back(p[i]);}

        if(remaining_plants.size() == num_of_plants) return days; // plants stops dying.
        else{
            days++;
            num_of_plants = remaining_plants.size(); // number of remaining plants
            p = remaining_plants; // remaining plants
        }
    }
}
