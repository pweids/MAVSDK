#include "param_server_impl.h"

namespace mavsdk {

ParamServerImpl::ParamServerImpl(std::shared_ptr<ServerComponent> server_component) :
    ServerPluginImplBase(server_component)
{
    // FIXME: this plugin should support various component IDs
    _server_component_impl->register_plugin(this);
}

ParamServerImpl::~ParamServerImpl()
{
    _server_component_impl->unregister_plugin(this);
}

void ParamServerImpl::init() {}

void ParamServerImpl::deinit() {}

std::pair<ParamServer::Result, int32_t> ParamServerImpl::retrieve_param_int(std::string name) const
{
    // FIXME: we need parameter server class
    // std::pair<MAVLinkParameters::Result, int> result = _parent->retrieve_server_param_int(name);

    // if (result.first == MAVLinkParameters::Result::Success) {
    //    return {ParamServer::Result::Success, result.second};
    //} else {
    //    return {ParamServer::Result::NotFound, -1};
    //}
    UNUSED(name);
    return {ParamServer::Result::Unknown, 0};
}

ParamServer::Result ParamServerImpl::provide_param_int(std::string name, int32_t value)
{
    // FIXME: we need parameter server class
    //_parent->provide_server_param_int(name, value);
    UNUSED(name);
    UNUSED(value);
    return ParamServer::Result::Unknown;
}

std::pair<ParamServer::Result, float> ParamServerImpl::retrieve_param_float(std::string name) const
{
    // FIXME: we need parameter server class
    // std::pair<MAVLinkParameters::Result, float> result =
    // _parent->retrieve_server_param_float(name);

    // if (result.first == MAVLinkParameters::Result::Success) {
    //    return {ParamServer::Result::Success, result.second};
    //} else {
    //    return {ParamServer::Result::NotFound, NAN};
    //}
    UNUSED(name);
    return {ParamServer::Result::Unknown, NAN};
}

ParamServer::Result ParamServerImpl::provide_param_float(std::string name, float value)
{
    // FIXME: we need parameter server class
    //_parent->provide_server_param_float(name, value);
    UNUSED(name);
    UNUSED(value);
    return ParamServer::Result::NoSystem;
}

ParamServer::AllParams ParamServerImpl::retrieve_all_params() const
{
    // auto tmp = _parent->retrieve_all_server_params();

    ParamServer::AllParams res{};

    // for (auto const& parampair : tmp) {
    //    if (parampair.second.is<float>()) {
    //        ParamServer::FloatParam tmp_param;
    //        tmp_param.name = parampair.first;
    //        tmp_param.value = parampair.second.get<float>();
    //        res.float_params.push_back(tmp_param);
    //    } else if (parampair.second.is<int32_t>()) {
    //        ParamServer::IntParam tmp_param;
    //        tmp_param.name = parampair.first;
    //        tmp_param.value = parampair.second.get<int32_t>();
    //        res.int_params.push_back(tmp_param);
    //    }
    //}

    // FIXME: we need parameter server class
    return res;
}

ParamServer::Result
ParamServerImpl::result_from_mavlink_parameters_result(MAVLinkParameters::Result result)
{
    switch (result) {
        case MAVLinkParameters::Result::Success:
            return ParamServer::Result::Success;
        case MAVLinkParameters::Result::NotFound:
            return ParamServer::Result::NotFound;
        case MAVLinkParameters::Result::ParamNameTooLong:
            return ParamServer::Result::ParamNameTooLong;
        case MAVLinkParameters::Result::WrongType:
            return ParamServer::Result::WrongType;
        default:
            LogErr() << "Unknown param error";
            return ParamServer::Result::Unknown;
    }
}

} // namespace mavsdk
