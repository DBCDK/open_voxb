<?php

/**
 * @file
 * OpenHoldingsStatus : open_holdingstatus class
 **/
class open_voxb extends TingClientRequest
{

    protected $outputType;
    protected $action;

    // paremeters for fetchDataRequest
    protected $fetchData;
    protected $objectIdentifierValue;
    protected $objectIdentifierType;
    protected $institutionId;
    protected $output;
    protected $callback;

    //additional parameters for createUserRequest
    protected $authenticationFingerprint;
    protected $userAlias;

    //additinal parameters for crateMyDataRequest
    protected $userId;
    protected $item;
    protected $object;

    //additional parameters for updateMyDataRequest
    protected $voxbIdentifier;

    /** \brief ITingClientRequestCache::cacheEnable; Check if cache is enabled
     *
     * @return value of variable (drupal_get)
     **/
    public function cacheEnable($value = NULL) {
        $class_name = get_class($this);
        return variable_get($class_name . TingClientRequest::cache_enable);
    }

    /** \brief set timeout of cache
     *
     * @return mixed value of variable (variable_get)
     **/
    public function cacheTimeout($value = NULL) {
        $class_name = get_class($this);
        return variable_get($class_name . TingClientRequest::cache_lifetime, '1');
    }

    /** \brief implements ITingClientRequestCache::cacheBin
     *
     * @return string; name of cachebin
     **/
    public function cacheBin() {
        return 'cache_bibdk_webservice';
    }

    public function getVoxbIdentifier(){
        return $this->voxbIdentifier;
    }

    public function setVoxbIdentifier($value){
        $this->voxbIdentifier = $value;
    }

    public function getItem(){
        return $this->item;
    }

    public function setItem($value){
        $this->item = $value;
    }

    public function getObject(){
        return $this->object;
    }

    public function setObject($value){
        $this->object = $value;
    }

    public function getUserId(){
        return $this->userId;
    }

    public function setUserId($value){
        $this->userId = $value;
    }

    public function getAuthenticationFingerprint() {
        return $this->authenticationFingerprint;
    }

    public function setAuthenticationFingerprint($value) {
        $this->authenticationFingerprint = $value;
    }

    public function getUserAlias() {
        return $this->userAlias;
    }

    public function setUserAlias($value) {
        $this->userAlias = $value;
    }

    public function setFetchData($value) {
        $this->fetchData = $value;
    }

    public function getFetchData() {
        return $this->fetchData;
    }

    public function setObjectIdentifierValue($value) {
        $this->objectIdentifierValue = $value;
    }

    public function getObjectIdentiferValue() {
        return $this->objectIdentifierValue;
    }

    public function setObjectIdentifierType($value) {
        $this->objectIdentifierType = $value;
    }

    public function getObjectIdentifierType() {
        return $this->objectIdentifierType;
    }

    public function setInstitutionId($value) {
        $this->institutionId = $value;
    }

    public function getInstitutionId() {
        return $this->institutionId;
    }


    public function setAction($value = NULL) {
        $this->action = $value;
    }

    public function getAction() {
        return $this->action;
    }

    public function getCallback() {
        return $this->callback;
    }

    public function setCallback($callback) {
        $this->callback = $callback;
    }

    public function setOutputType($value = NULL) {
        $this->outputType = $value;
    }

    public function getOutputType() {
        return $this->outputType;
    }

    public function setOutput($value) {
        $this->output = $value;
    }

    public function getOutput() {
        return $this->output;
    }

    public function getRequest() {
        $service_url = variable_get('open_voxb_url');
        if (function_exists('ting_client_validate_xsd')) {
            $params = ting_client_validate_xsd('voxb.xsd', $this->getAction());
        } else
            throw new Exception("Validation is needed for voxb");
        foreach ($params as $parameter) {
            $getter = 'get' . ucfirst($parameter);
            if ($value = $this->$getter()) {
                $this->setParameter($parameter, $value);
            }
        }
        return $this;
    }

    // empty;
    public function processResponse(stdClass $result) {
        return $result;
    }

}
