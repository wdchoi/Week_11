#include <iostream>
#include <vector>
class Neuron
{
public:
	float a_ = 0.0f;
	float b_ = 0.0f;
	float a_2_ = 0.0f;
	float b_2_ = 0.0f;
	float getY(const float& x_input)
	{
		return a_ * x_input + b_;
	}
	float get_2_Y(const float& x_input) {
		return a_2_ *(getY(x_input)) + b_2_;
	}
};

int main()
{
	std::vector<float> study_time_data;
	std::vector<float> score_data;

	Neuron lh;
	const int num_data = 5;
	const float lr = 0.01;

	study_time_data.push_back(0.1);
	study_time_data.push_back(0.2);
	study_time_data.push_back(0.3);
	study_time_data.push_back(0.4);
	study_time_data.push_back(0.5);

	score_data.push_back(4);
	score_data.push_back(5);
	score_data.push_back(6);
	score_data.push_back(7);
	score_data.push_back(8);

	for (int tr = 0; tr < 5000; tr++)
		for (int i = 0; i < num_data; i++)
		{
			const float x_input = study_time_data[i];
			const float y_output = lh.get_2_Y(x_input);
			const float y_target = score_data[i];
			const float error = y_output- y_target;

			const float sqr_error = 0.5 * error * error;

			const float dse_over_da = error * lh.a_2_*x_input;
			const float dse_over_db = error*lh.b_2_;
			const float dse_over_da_1 = error * (lh.a_*x_input+ lh.b_);
			const float dse_over_db_1 = error*1;

			lh.a_ -= dse_over_da * lr;
			lh.b_ -= dse_over_db * lr;
			lh.a_2_ -= dse_over_da_1 * lr;
			lh.b_2_ -= dse_over_db_1 * lr;

			std::cout << "x_input=" << x_input << " y_target=" << y_target
				<< " y_output=" << y_output << " sqr_error = " << sqr_error << std::endl;
		}
	std::cout << "a=" << lh.a_ << " b=" << lh.b_ << " c=" << lh.a_2_<< " d="<< lh.b_2_<< std::endl;
	std::cout << "From trained hypothesis: "<<"input = 0.7 output=" << lh.get_2_Y(0.7) << std::endl;
	return 0;
}