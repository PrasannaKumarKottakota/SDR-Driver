#include <SoapySDR/Device.hpp>
#include <SoapySDR/Registry.hpp>
#include <iostream>
class MyDevice : public SoapySDR::Device
{
public:
    	
    MyDevice(void)
    {
        return;
    }

    std::string getDriverKey(void) const
    {
        return "MyRF";
    }

    std::string getHardwareKey(void) const
    {
        return "MYRF007";
    }
	
	std::string getVendorInfo(void) const
    {
        return "Prasanna kumar";
    }
    
    SoapySDR::Kwargs getHardwareInfo(void) const
    {

        SoapySDR::Kwargs args;
        
        args["Developer"] = "Prasanna Kumar";
        std::cout<<"I am in getHardwareInfo "<<std::endl;
        
        return args;
    }
    
//##### Channel Functions ######
//#### Frequency Functions ######
//###### Gain Functions ########
    
// ######## Stream API's are as following
     
     
SoapySDR::Stream *setupStream(
   const int direction,
   const std::string &format,
   const std::vector<size_t> &channels,
   const SoapySDR::Kwargs &args)
   {
   std::cout<<"I am in Setup Stream "<<std::endl;
   return (SoapySDR::Stream *) this;
	}

int activateStream(
	SoapySDR::Stream *stream,
	const int flags = 0,
	const long long timeNs = 0,
	const size_t numElems = 0)
	{
	std::cout<<"I am activate Stream"<<std::endl;
	return 10;
	}
		
int readStream(
   SoapySDR::Stream *stream,
   void * const *buffs,
   const size_t numElems,
   int &flags,
   long long &timeNs,
   const long timeoutUs )
   { 
	std::cout<<"I am in readStream"<<std::endl;
	return 0;
    }
  
int writeStream(
   SoapySDR::Stream *stream,
   const void * const *buffs,
   const size_t numElems,
   int &flags,
   const long long timeNs,
   const long timeoutUs )
	{
	std::cout<<buffs<<std::endl;
	std::cout<<"I am in writeStream "<<std::endl;    
    return 0;
	}
	
int deactivateStream(
    SoapySDR::Stream *stream,
    const int flags = 0,
    const long long timeNs = 0)
    {
	std::cout<<"I am in Deactivae Stream"<<std::endl;
	return 0;	
	}
	

void closeStream(SoapySDR::Stream *stream)
	{
	std::cout<<"I am in close Stream"<<std::endl;
	return;
	}	 
	      
};


SoapySDR::KwargsList SoapySDR::Device::enumerate(const Kwargs&)
    {
        SoapySDR::KwargsList enum_results;
        SoapySDR::Kwargs enumArgs;

        enumArgs["driver"] = "MyDevice";
        enumArgs["type"] = "MyDevice";
       
    
        enum_results.push_back(enumArgs);
        return enum_results;

    }

SoapySDR::KwargsList findMyDevice(const SoapySDR::Kwargs &args)
{
    SoapySDR::KwargsList results;

    if (args.count("type") == 0) return results;
    if (args.at("type") != "MyDevice") return results;

    SoapySDR::Kwargs MyArgs;
    MyArgs["type"] = "MyDevice";
    
    results.push_back(MyArgs);

    return results;
}

SoapySDR::Device *makeMyDevice(const SoapySDR::Kwargs &)
{
    return new MyDevice();
}

static SoapySDR::Registry registerMyDevice("MyDevice", &findMyDevice, &makeMyDevice, SOAPY_SDR_ABI_VERSION);

